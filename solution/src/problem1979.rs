impl Solution {
    // 求最大公约数
    pub fn gcd(mut x: i32, mut y: i32) -> i32 {
        while x != 0 {
            let r = y % x;
            y = x;
            x = r;
        }
        y
    }
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 0 {
            return 0;
        }else if n == 1 {
            return nums[0];
        }
        let (mut max,mut min) = (nums[0],nums[0]);
        for num in nums{
            if num > max {
                max = num;
            }
            if num < min {
                min = num;
            }
        }
        Solution::gcd(max,min)
    }

}

struct Solution;

fn main() {
    let nums = vec![2,4,6,8,10];
    println!("{}",Solution::find_gcd(nums));
    // println!("Hello, world!");
}
