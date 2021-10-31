package queue.importantQuestions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;

public class SlidingWindowMaximum{

    public int[] maxSlidingWindow(int[] arr, int k) {
        int n = arr.length;
        Deque<Integer> deque = new LinkedList<>();
        int[] output  = new int[n-k+1];
        for(int  i =0;i<arr.length;i++){
            if(!deque.isEmpty()&&deque.getFirst()<(i-k+1)){
      //          System.out.println("hello");
                while (!deque.isEmpty()&&deque.getFirst()<(i-k+1)){
                    deque.removeFirst();
                }
            }
            if(deque.isEmpty())
                deque.addFirst(i);
            else if(arr[i]>arr[deque.getFirst()]){
                while (!deque.isEmpty() && arr[deque.getFirst()]<arr[i]){
                    deque.removeFirst();
                }
                deque.addFirst(i);
            }
            else if(arr[i]<=arr[deque.getLast()]){
                deque.addLast(i);
            }
            else if(arr[i]>arr[deque.getLast()]){

                while (!deque.isEmpty()&&arr[i]>arr[deque.getLast()]){
                    deque.removeLast();
                }
                deque.addLast(i);
            }

            if(!deque.isEmpty()&&i-k+1>=0){
                output[i-k+1]=arr[deque.getFirst()];
            }
        //   System.out.println(deque);
        }
        return output;
    }

    public static void main(String[] args){
        int[] arr = {1,3,1,2,0,5};
        int k =3;
        SlidingWindowMaximum obj = new SlidingWindowMaximum();
        System.out.println(Arrays.toString(obj.maxSlidingWindow(arr,k)));
    }

}
