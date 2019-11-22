// 1. 理解方法的基本用法, 方法重载, 方法递归, 并写一篇博客总结. 
// 2. 实现代码: 递归求 N 的阶乘 
// 3. 实现代码: 递归求 1 + 2 + 3 + ... + 10 
// 4. 实现代码: 按顺序打印一个数字的每一位(例如 1234 打印出 1 2 3 4) 
// 5. 实现代码: 写一个递归方法，输入一个非负整数，返回组成它的数字之和. 


// class Test{
//     public static void main(String[] args){
//         int a = 10;
//         int b = 20;
//         int ret = add(a , b);
//         System.out.println(ret);
//     } 

//     public static int add(int x, int y){
//         return x+y;
//     }
// }



// 递归求N的阶乘
// class Test{
//     public static void main(String[] args){
//         int n = 3;
//         int ret = factor(n);
//         System.out.println("ret = " + ret);
//     }

//     public static int factor(int n){
//         if(n == 1){
//             return 1;
//         }
//         return n * factor(n - 1);
//     }
// }


// 实现代码: 递归求 1 + 2 + 3 + ... + 10 
// class Test{
//     public static void main(String[] args){
//         int num = 10;
//         int ret = sum(num);
//         System.out.println("ret = "+ret);
//     }
//     public static int sum(int num){
//         if(num == 1){
//             return 1;
//         }
//         return num +sum(num -1);
//     }
// }

// 按顺序打印一个数字的每一位(例如 1234 打印出 1 2 3 4) 

// class Test{
//     public static void main(String[] args){
//         int num = 1234;
//         print(num);
//     }

//     public static void print(int num){
//         if(num > 9){
//             print(num / 10);
//         }
//         System.out.println(num % 10);
//     }
// }



// 写一个递归方法，输入一个非负整数，返回组成它的数字之和. 
// class Test{
//     public static void main(String[] args){
//         int num = 9527;
//         int ret = sum(num);
//         System.out.println("ret = " + ret);
//     }

//     public static int sum(int num){
//         if (num < 10){
//             return num;
//         }
//         return num%10 + sum(num/10);
//     }
// }



// class Test {
//     public static void main(String[] args) {
//         int a = 10;
//         int b = 20;       
//         swap(a, b);      
//         System.out.println("a = " + a + " b = " + b); 
//     }
//     public static void swap(int x, int y) {     
//         int tmp = x;   
//         x = y;    
//         y = tmp;  
//     }
// }
// 运行结果 a = 10 b = 20 


// class Test {
//     public static void main(String[] args) {  
//         int[] arr = {10, 20}; 
//         swap(arr);       
//         System.out.println("a = " + arr[0] + " b = " + arr[1]); 
//     }
//     public static void swap(int[] arr) { 
//         int tmp = arr[0];  
//         arr[0] = arr[1];    
//         arr[1] = tmp;    
//     } 
// }
// 运行结果 a = 20 b = 10


 //求斐波那契数列的第 N 项 
 class Test{
     public static void main(String[] args){
        System.out.println(fib(100));
     }
     public static int fib(int n){
         if ( n == 1 || n == 2){
             return 1;
         }
         return fib(n - 1) + fib(n - 2);
     }
 }



//汉诺塔问题
class Test{
    public static void main ( String[] args){
        move(1, 'a', 'b', 'c');
    }
    public static void move(int n, char a, char b, char c){
        if( n == 1){
            System.out.println(a + "->" + c);
        }
        else{
            move( n - 1, a, c, b);//将n-1个盘子从a借助c移到b上
            System.out.println(a + "->" + c);//将a最底下第n个盘子移到c上
            move(n - 1, b, a, c);//将n-1个盘子从b借助a移到c上
        }
    }
}


//青蛙跳台阶问题:
//一只青蛙一次可以跳上 1 级台阶，也可以跳上2 级。求该青蛙跳上一个n 级的台阶总共有多少种跳法 
class Test{
    public static void main(String[] args){
        int n = 3;
        int ret = forgStep(n);
        System.out.println( ret );
    }
    public static int forgStep(int n){
        if(n <= 2){
            return n;
        }
        else {
            return forgStep(n - 1) + forgStep(n - 2);
        }
    }
}
