import java.util.Scanner;
class Test{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入你的年龄：");
        int age = sc.nextInt(); 
        if(age <=18 && age > 0){
            System.out.println("少年");
        }
        else if (age > 18 && age <= 28 ){
            System.out.println("青年");
        }
        else if (age > 28 && age <= 55 ){
            System.out.println("中年");
        }
        else if (age > 55 ){
            System.out.println("老年");
        }
    }
}



// 判断一个数是不是素数
import java.util.Scanner;
class Test{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入一个数：");
        int num = sc.nextInt(); 
        if (num == 1){
            System.out.println(num + "不=是素数");
        }
        int i =2;
        for(i = 2; i < num; i++){
            if ( num % i == 0 ){
                System.out.println(num + "不是素数");
                break;
            }
        }           
        if( num == i){
            System.out.println(num + "是素数");
        }
    }
}


//打印 1 - 100 之间所有的素数
class Test{
     public static void main(String[] args){
        for(int num = 2; num <= 100; num++){
            int i =2;
            for(i = 2; i < num; i++){
                if ( num % i == 0 ){
                    break;
                }
            }           
            if( num == i){
             System.out.println(num + "是素数");
            }
        }
    }
}



//输出 1000 - 2000 之间所有的闰年
class Test{
     public static void main(String[] args){
        for(int year = 1000; year <=2000; year++){
            if(year % 4 ==0 && year % 100 != 0 || year % 400 ==0){
                System.out.println(year);
            }
        }
    }
}


//输出乘法口诀表
class Test{
     public static void main(String[] args){
        for(int row = 1; row < 9; row++){
            for(int col = 1; col <= row; col++){
                System.out.print( col+"*"+row+"=" + row*col+"\t");
            }
            System.out.println();
        }
    }
}


//求两个正整数的最大公约数 
class Test{
     public static void main(String[] args){
         int a = 64;
         int b = 48;
         while( b != 0){
             int i = a % b;
             a = b;
             b = i;
         }
         System.out.println("最大公约数为"+a);
    }
}


//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
class Test{
     public static void main(String[] args){
        int i = 1;
        double sum = 0;
        for(i = 1; i <= 100; i++){
            sum = sum + ((1.0/i)*(Math.pow(-1,(i+1))));
        }
         System.out.println(sum);
    }
}

//编写程序数一下 1到 100 的所有整数中出现多少个数字9。
class Test{
    public static void main(String[] args){
        int sum = 0;
        for(int i = 1; i <= 100; i++){
            if(i % 10 == 9 ){
            sum++;
            }
            if(i / 10 == 9){
                sum++;
            }
        }
         System.out.println(sum);
    }
}


//求出0～999之间的所有“水仙花数”并输出
class Test{
    public static void main(String[] args){
        int i, j;
        int a, b, c;
        for(i = 100; i<=999; i++){
            a = i / 100;
            b = (i / 10) % 10;
            c = i % 10;
            j = a*a*a + b*b*b + c*c*c; 
            if (i == j){
                System.out.println(i);
            }  
        }
    }
}


//编写代码模拟三次密码输入的场景。 
//最多能输入三次密码，密码正确，提示“登录成功”,密码错误， 
//可以重新输入，最多输入三次。三次均错，则提示退出程序 
import java.util.Scanner;
class Test{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i<3; i++){
            System.out.println("请输入用户名");
            String name = sc.nextLine(); 
            System.out.println("请输入密码");
            String code = sc.nextLine(); 
            if("1234".equals(code) && "nuonuo".equals(name)){
                System.out.println("登陆成功");
                break;
            }
            else if (i == 2){
                System.out.println("三次均输入错误，即将退出程序");
                break;
            }
            System.out.println("输入错误，请重新输入");
        }
    }
}



//写一个函数返回参数二进制中 1 的个数 
//比如： 15 0000 1111 4 个 1 
import java.util.Scanner;
class Test{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入一个数：");
        int num = sc.nextInt(); 
        int count = 0;
        while (num != 0){
            if ((num & 1) == 1){
                ++count;
            }
            num = num >> 1;
        }
        System.out.println(count);
    }
}


//输出一个整数的每一位. 
class Test{
    public static void main (String[] args){
        int num = 9527;
        print(num);
    }
    public static void print(int num){
        if(num != 0){
            print(num / 10);
            System.out.println(num % 10);
        }
    }
}


//完成猜数字游戏
import java.util.Random;
import java.util.Scanner;;
class Test{
    public static void main (String[] args){
        Random random = new Random();
        Scanner sc = new Scanner(System.in);
        int toGuess = random.nextInt(100);
        while(true){
            System.out.println("游戏开始，请输入1-100之间的数字");
            int num = sc.nextInt();
            if(num < toGuess){
                System.out.println("底了");
            }else if (num > toGuess){
                 System.out.println("高了");
            }else{
                 System.out.println("猜对了");
                 break;
            }
        }
        sc.close();
    }
}
