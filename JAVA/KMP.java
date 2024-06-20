public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        while(n-- > 0){
            String s = sc.next();
            String pattern = sc.next();

            kmp(s, pattern);
        }
    }

    private static void kmp(String haystack, String needle){
        haystack = needle + "#" + haystack;
        int[] dp = new int[haystack.length()];
        int len = 0;

        for(int i=1; i<dp.length;){
            if(haystack.charAt(len) == haystack.charAt(i)){
                len++;
                dp[i] = len;
                i++;
            }
            else{
                if(len > 0){
                    len = dp[len-1];
                }
                else{
                    dp[i] = 0;
                    i++;
                }
            }
        }

        int n = needle.length();
        ArrayList<Integer> res = new ArrayList<>();

        for(int i=n+1; i<dp.length; i++){
            if(dp[i]==n){
                res.add(i-(2*n)+1);
            }
        }

        if(res.size() > 0){
            System.out.println(res.size());
            for(int i : res){
                System.out.print(i+" ");
            }
            System.out.println();
        }
        else{
            System.out.println("Not Found");
        }

    }
}
