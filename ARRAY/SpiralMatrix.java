package arrays;

import com.sun.xml.internal.ws.util.pipe.StandalonePipeAssembler;

import java.util.ArrayList;
import java.util.List;

public class SpiralMatrix {

    public List<Integer> spiralOrder(int[][] arr) {
        int i = 0, j = 0;
        int n1 = arr.length;
        int n2 = arr[0].length;
        int min = Integer.MIN_VALUE;
        List<Integer> list = new ArrayList<>();
        list.add(arr[i][j]);
        arr[i][j] = min;
        int count = 0;
        int c = 0;
        while (true) {

            if (c == count) {
                if (j + 1 < n2 && arr[i][j + 1] != min && c == 0) {
                    list.add(arr[i][j + 1]);
                    arr[i][j + 1] = min;
                    j++;
                    count = 0;
                } else if (i + 1 < n1 && arr[i + 1][j] != min && c == 1) {

                    list.add(arr[i + 1][j]);
                    arr[i + 1][j] = min;
                    i++;
                    count = 1;
                } else if (j - 1 >= 0 && arr[i][j - 1] != min && c == 2) {

                    list.add(arr[i][j - 1]);
                    arr[i][j - 1] = min;
                    j--;
                    count = 2;
                } else if (i - 1 >= 0 && arr[i - 1][j] != min && c == 3) {

                    list.add(arr[i - 1][j]);
                    arr[i - 1][j] = min;
                    i--;
                    count = 3;
                } else
                    count = 4;
            } else {

                if (j + 1 < n2 && arr[i][j + 1] != min) {
                    list.add(arr[i][j + 1]);
                    arr[i][j + 1] = min;
                    j++;
                    c = 0;
                    count = 0;
                } else if (i + 1 < n1 && arr[i + 1][j] != min) {

                    list.add(arr[i + 1][j]);
                    arr[i + 1][j] = min;
                    i++;
                    c = 1;
                    count = 1;
                } else if (j - 1 >= 0 && arr[i][j - 1] != min) {

                    list.add(arr[i][j - 1]);
                    arr[i][j - 1] = min;
                    j--;
                    c = 2;
                    count = 2;
                } else if (i - 1 >= 0 && arr[i - 1][j] != min) {

                    list.add(arr[i - 1][j]);
                    arr[i - 1][j] = min;
                    i--;
                    c = 3;
                    count = 3;
                } else {
                    break;
                }
            }
        }
        return list;


    }

    public static void main(String[] args) {
        SpiralMatrix obj = new SpiralMatrix();
        int[][] arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        System.out.println(obj.spiralOrder(arr));
    }


}
