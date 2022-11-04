package practice.uva;

import static java.lang.Integer.MAX_VALUE;
import static java.lang.Integer.bitCount;
import static java.lang.Integer.min;
import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
public class UVa1281 {
	static int N;
	static int mAdy[][];
	static int mem[][][];
	static int tsp(int A,int u,int v) {
		if(A==(1<<(N-2))-1)return mAdy[u+1][v];
		if(mem[v==0?0:1][u][A]>=0)return mem[v==0?0:1][u][A]; 
		int min=MAX_VALUE;
		for(int i=0;i<N-2;i++)
			if((A&(1<<i))==0)
				min=min(min,tsp(A|(1<<i),i,v)+mAdy[u+1][i+1]);
		return mem[v==0?0:1][u][A]=min;
	}
	public static void main(String args[]) throws Throwable {
		mem=new int[2][18][1<<18];
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int caso=1;
		for (String ln;(ln=in.readLine())!=null;caso++) {
			StringTokenizer st=new StringTokenizer(ln);
			N=parseInt(st.nextToken());
			int M=parseInt(st.nextToken());
			mAdy=new int[N][N];
			for(int i=0;i<N;i++) {
				Arrays.fill(mAdy[i], 3600*400);
				mAdy[i][i]=0;
			}
			for(int i=0;i<M;i++) {
				st=new StringTokenizer(in.readLine());
				int d=parseInt(st.nextToken()),h=parseInt(st.nextToken()),c=parseInt(st.nextToken());
				mAdy[d][h]=mAdy[h][d]=min(c,mAdy[h][d]);
			}
			for(int k=0;k<N;k++)
				for(int i=0;i<N;i++)
					for(int j=0;j<N;j++)
						mAdy[i][j]=min(mAdy[i][j],mAdy[i][k]+mAdy[k][j]);
			int res=0;
			for(int i=0;i<2;i++)
				for(int j=0;j<N-2;j++)
					for(int h=0;h<1<<N-2;h++) 
						mem[i][j][h]=-1;
			if(N>3) {
				res=MAX_VALUE;
				for(int i=0;i<(1<<(N-2));i++)
					if(bitCount(i)==(N-2)/2) {
						int ida=MAX_VALUE,vuelta=MAX_VALUE;
						for(int j=0;j<N;j++)
							if((i&(1<<j))!=0) {
								ida=min(ida,tsp(i,j,N-1)+tsp((i^((1<<(N-2))-1))|(1<<j),j,0));
								vuelta=min(vuelta,tsp(i,j,0)+tsp((i^((1<<(N-2))-1))|(1<<j),j,N-1));
							}
						res=min(res,ida+vuelta);
					}
			}
			else res=2*(tsp(1,0,N-1)+tsp(1,0,0));
			sb.append("Case ").append(caso).append(": ").append(res).append("\n");
		}
		System.out.print(new String(sb));
	}
}