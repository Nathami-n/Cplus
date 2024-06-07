public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world");
        Car mine = new Car(2, "nathan");

        System.out.println(mine.name + " " + mine.name);
    }

     static class Car {
        int number;
        String name;
        public Car(int no, String name) {
            this.number = no;
            this.name = name;
        }
    };




}