impl Solution {
    pub fn min_time_to_type(word: String) -> i32 {
        let mut ans = 0;
        //prev 初始为a
        let mut prev = 'a';
        //c从word开始遍历
        for c in word.chars(){
            //如果c和prev相同，则ans加1
            if c == prev {
                ans += 1;
            }else{
                let t:i32 = (c as i32 - prev as i32 + 26 ) % 26;
                //取t和26-t的最小值
                ans += std::cmp::min(t, 26-t)+1;

            }
            //prev更新为c
            prev = c;
        }
        ans
    }
}
struct Solution;

fn main(){
    let ans = Solution::min_time_to_type("zjpc".to_string());
    println!("{}", ans);
}