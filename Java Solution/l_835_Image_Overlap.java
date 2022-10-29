// Link: https://leetcode.com/problems/image-overlap/

import java.util.*;


class l_835_Image_Overlap {
    public int largestOverlap(int[][] A, int[][] B) {
        int N = A.length;
        List<Integer> LA = new ArrayList();
        List<Integer> LB = new ArrayList();

        for (int i = 0; i < N*N; ++i)
            if (A[i/N][i%N] == 1)
                LA.add(i / N * 100 + i % N);
        for (int i = 0; i < N*N; ++i)
            if (B[i/N][i%N] == 1)
                LB.add(i / N * 100 + i % N);

        Map<Integer, Integer> count = new HashMap();
        for (int i: LA)
            for (int j: LB)
                count.put(i-j, count.getOrDefault(i-j, 0) + 1);

        int res = 0;
        for (int i: count.values())
            res = Math.max(res, i);
        return res;
    }

    public static void main(String[] args) {
        l_835_Image_Overlap solution = new l_835_Image_Overlap();
        int[][] A = {{1,1,0},{0,1,0},{0,1,0}};
        int[][] B = {{0,0,0},{0,1,1},{0,0,1}};
        System.out.println(solution.largestOverlap(A, B));
    }
}
