class Solution {
    public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        int n1 = num1.length();
        int n2 = num2.length();
        int[] product = new int[n1+n2];
        for(int i=n1-1; i>=0; i--) {
            for(int j=n2-1; j>=0; j--) {
                product[i+j+1] += ((int)num1.charAt(i) - '0') * ((int)num2.charAt(j) - '0');
            }
        }
        for(int i=product.length-1; i>=0; i--) {
            if(product[i]>9) {
                int carry = product[i] / 10;
                int base = product[i] % 10;
                product[i] = base;
                product[i-1] = product[i-1] + carry;
            }
        }
        StringBuilder sb = new StringBuilder();
        boolean areleadingZeroesHandled = false;
        for(int element : product) {
            if(!areleadingZeroesHandled && element == 0) {
                continue;
            }
            areleadingZeroesHandled = true;
            sb.append(element);
        }
        return sb.toString();
    }
}
