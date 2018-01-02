import java.util.*;
import java.io.*;

public class Hangman{
    public static void main(String[] args){
        List<String> list = new ArrayList<>();
        list.add("parallel");
        list.add("leetcode");
        list.add("linkedin");
        Scanner in = new Scanner(System.in);
        Random rand = new Random();
        boolean isPlaying = true;
        int guessCnt = 0, maxGuess = 6, len = 0;
        String str = null, input = null;
        char ch = ' ';
        System.out.println("Welcome to Hangman Game.");
        while(isPlaying){
            //System.out.println("Welcome to Hangman Game.");
            guessCnt = 0;
            str = list.get(rand.nextInt(list.size()));
            len = str.length();
            char[] strArr = str.toCharArray();
            char[] userArr = new char[len];
            for(int i = 0; i < len; ++i) userArr[i] = '_';
            while(guessCnt < maxGuess){
                displayUserArr(userArr);
                System.out.println("Remaining number of guess: " + (maxGuess - guessCnt));
                input = in.nextLine();
                ch = input.charAt(0);
                for(int i = 0; i < len; ++i){
                    if(ch == strArr[i]){
                        userArr[i] = ch;
                    }
                }
                if(checkWin(userArr)){
                    System.out.println("you won.");
                    break;
                }
                ++guessCnt;
                if(guessCnt == maxGuess){
                    System.out.println("you lose");
                }
            }
            System.out.println("Conitnue game or not? yes/no");
            input = in.nextLine();
            isPlaying = input.equals("yes");
        }
        System.out.println("game over");
    }

    public static void displayUserArr(char[] userArr){
        for(int i = 0; i < userArr.length; ++i){
            System.out.print(userArr[i] + " ");
        }
        System.out.println();
    }

    public static boolean checkWin(char[] userArr){
        for(int i = 0;i < userArr.length; ++i){
            if(userArr[i] == '_') return false;
        }
        return true;
    }
}
