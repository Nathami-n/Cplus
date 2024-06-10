import java.util.*;
public class Main {
    public static void main(String[] args) {

        System.out.println(generateRandomNumber(10));

    };

    public static int generateRandomNumber(int range) {
        double randomFloat = Math.random();
         return (int) (randomFloat * range + 1);
    }
}