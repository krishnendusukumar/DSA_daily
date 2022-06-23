class Solution {
    public int scheduleCourse(int[][] arr) {
         	Arrays.sort(arr, new Comparator<int[]>(){
		@Override
		public int compare(int[] arr1, int[] arr2){
			return arr1[1]-arr2[1];
		}
	});
	PriorityQueue<Integer> q=new PriorityQueue<>(new Comparator<Integer>(){
		@Override
		public int compare(Integer i1, Integer i2){
			return i2-i1;
		}
	});
        long sum = 0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i][0];
            q.add(arr[i][0]);
            if(sum>arr[i][1]) {
                sum-=q.element();
                q.remove();
            }
        }
        return q.size();

    }
}