package lpsolve_test;
import lpsolve.*;
import java.util.Arrays;


public class Optimator {
	private static LpSolve problem;
	/**
	 * ��������滮����
	 * @param goal			Ŀ�꺯����������LpSolve��ȡ����ʱ���±�1��ʼ��ȡ����������±�1��ʼ��䣬0-1�ķ�ǰ�棬�����޵ķź���
	 * @param stIeMatrix	����ʽԼ�����̾�������LpSolve��ȡ����ʱ���±�1��ʼ��ȡ���ڲ���������±�1��ʼ���
	 * @param stEqMatrix	��ʽԼ�����̾�������LpSolve��ȡ����ʱ���±�1��ʼ��ȡ���ڲ���������±�1��ʼ���
	 * @param stIeRest		����ʽԼ����������ÿ�δ�����ǵ������֣�����Ҫ��1��ʼ���
	 * @param stEqRest		��ʽԼ����������ÿ�δ�����ǵ������֣�����Ҫ��1��ʼ���
	 * @param ups			����Լ������
	 */
	public static void optimate(double[] goal,double[][] stIeMatrix,double[][] stEqMatrix,
			double[] stIeRest,double[] stEqRest,double[] ups) throws LpSolveException{

		//1������LpSolve����
		problem = LpSolve.makeLp(0, goal.length-1);
		//2�����Ŀ�꺯��������±�1��ʼ��ȡ!�±�1�Ĳ����ᱻ����
		problem.setObjFn(goal);
		
		//3��ѭ����Ӳ���ʽԼ�������ѭ��һ�δ���һ������ʽ
		if(stIeMatrix!=null){
			for(int i=0;i<stIeMatrix.length;i++){
				//ͬ������Ķ�ȡ����±�1��ʼ
				problem.addConstraint(stIeMatrix[i], LpSolve.LE, stIeRest[i]);
			}
		}
		
		//4��ѭ����ӵ�ʽԼ�������ѭ��һ�δ���һ����ʽ
		if(stEqMatrix!=null){
			for(int i=0;i<stEqMatrix.length;i++){
				//ͬ������Ķ�ȡ����±�1��ʼ
				problem.addConstraint(stEqMatrix[i], LpSolve.EQ, stEqRest[i]);
			}
		}
		
		//5�����ò���������Լ����1�����һ������
		for(int i=1;i<goal.length;i++){
			problem.setInt(i, true);
		}
		
		//6������ָ������������ֵ
		for(int i=1;i<=ups.length;i++){
			problem.setUpbo(i, ups[i-1]);
		}
		
		problem.printLp();
		//���
		problem.solve();
	}
	/**
	 * �õ����Ž�
	 * @return
	 * @throws LpSolveException
	 */
	public static double getObjective() throws LpSolveException{
		if(problem!=null){
			return problem.getWorkingObjective();
		}else{
			try {
				throw new Exception("��û�н�����⣡");
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} 
			return 0;
		}
	}
	/**
	 * �õ����Ž��Ӧ�ı���
	 * @return
	 * @throws LpSolveException
	 */
	public static double[] getVariables() throws LpSolveException{
		if(problem!=null){
			return problem.getPtrVariables();
		}else{
			try {
				throw new Exception("��û�н�����⣡");
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} 
			return null;
		}
	}
	
//����
	public static void main(String[] args) {
		try {
			double[][] stIeMatrix = new double[1][];
			stIeMatrix[0] = new double[]{0,1,2,3,4};
			double[] stRest = new double[]{1};
			optimate(new double[]{0,1,2,3,4},stIeMatrix,stIeMatrix,stRest,stRest,new double[]{1,1,5,6});
			System.out.println(getObjective());
			System.out.println(Arrays.toString(getVariables()));
		} catch (LpSolveException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
