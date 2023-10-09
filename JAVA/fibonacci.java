 class fibonacci {
    public static void main(String[] args) {
        for(int i = 0; i < 11; i++){
            System.out.print(fibocci(i));
            System.out.print(" ");
        }
        System.out.println();
        for(int i = 0; i<11; i++){
            System.out.print(fibocci2(i));
            System.out.print(" ");
        }
        System.out.println('v');
        System.out.println(fibocci(3));

    }
    static int fibo(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int c = fibo(n-1)+fibo(n-2);
//        System.out.print(c);
        return c;
    }

    static int fibocci(int n){
        return (int)((1/Math.sqrt(5))*(Math.pow(((1+Math.sqrt(5))/2),n) - Math.pow(((1-Math.sqrt(5))/2),n)));
    }

    static int fibocci2(int n){
        return (int)((1/Math.sqrt(5))*(Math.pow(((1+Math.sqrt(5))/2),n)));
    }
}
