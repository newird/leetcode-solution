impl Solution {
    pub fn minimum_difference(nums: Vec<i32>, k: i32) -> i32 {
        if k == 1 {return 0};
        let mut nums = nums;
        nums.sort();
        let mut min = std::i32::MAX;
        println!("{:?}", nums);
        println!("{}", nums.len()-k as usize);
        for i in 0..nums.len() - k as usize +1 {
            min = std::cmp::min(min, nums[i + k  as usize -1] - nums[i]);
            println!("{} {}", nums[i + k as usize -1], nums[i]);
        }
        min
    }
}
struct Solution;
fn main() {
  assert_eq!(2, Solution::minimum_difference(vec![9,4,1,7], 2));
    println!("Hello, world!");
}
