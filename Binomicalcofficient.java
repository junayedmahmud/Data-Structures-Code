class Binomicalcofficient {

    public static int Binomicalcofficient(int n,int k)
    {
        int c[][]=new int[n+1][k+1];

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=min(i,k);j++)
            {
                if(j==0||i==j)
                {
                    c[i][j]=1;
                    System.out.println("c["+i+"]["+j+"]=1");
                }
                else
                {
                    c[i][j]=c[i-1][j-1]+c[i-1][j];
                    System.out.println("c["+i+"]["+j+"]="+(c[i-1][j-1]+c[i-1][j]));
                }
            }

            System.out.println();
        }

        return c[n][k];
    }

    public static int min(int a,int b)
    {
        return (a<b)?a:b;
    }

    public static void main(String[] args) {

        int n=5,k=2;

        int result=Binomicalcofficient(n,k);

        System.out.println(result);
    }
}
