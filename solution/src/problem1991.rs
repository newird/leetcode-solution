impl Solution {
    pub fn find_middle_index(nums: Vec<i32>) -> i32 {
        //prev =0 ,total= nums 的和

       let (mut prev,total) = (0,nums.iter().sum::<i32>());
        for i in 0..nums.len()  {
           if (prev << 1) + nums[i] == total {
               return i as i32;
           }
           prev += nums[i];
        }
        -1
    }
}
struct Solution;
fn main() {
    let ans:i32 = Solution::find_middle_index(vec![2,3,-1,8,4]);
    println!("{:?}", ans);
    println!("Hello, world!");
}
