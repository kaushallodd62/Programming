public class Prime {
    public static void main(String[] args) {
        int n = 100;
        boolean[] prime = new boolean[n+1];
        for(int i=0; i<=n; i++)
            prime[i] = true;
        for(int i=2; i*i <= n; i++) {
            if (prime[i]) {
                for (int j=i*i; j<=n; j+=i)
                    prime[j] = false;
            }
        }
        for(int i=1; i<=n; i++) {
            if(prime[i])
                System.out.print(i + " ");
        }
        System.out.println();
    }
}
