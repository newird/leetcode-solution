use std::collections::HashMap;
use rand::prelude::*;
impl RandomizedSet {

     fn new() -> Self {
        Self {
            map: HashMap::new(),
            vec: Vec::new(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        if self.map.contains_key(&val) {
            return false;
        }
        self.map.insert(val, self.vec.len());
        self.vec.push(val);
        true
    }

    fn remove(&mut self, val: i32) -> bool {
        if !self.map.contains_key(&val) {
            return false;
        }
        let index = self.map[&val];
        let last = self.vec.len() - 1;
        self.vec.swap(index, last);
        //把vec[last]在map中的值改为index
        self.map.insert(self.vec[index], index);

        self.map.remove(&val);
        self.vec.pop();

        true
    }

    fn get_random(&self) -> i32 {
        self.vec[rand::thread_rng().gen_range(0, self.vec.len())]
    }
}
struct RandomizedSet {
    map: HashMap<i32, usize>,
    vec: Vec<i32>,
}

pub(crate) fn test(){
    let mut set = RandomizedSet::new();
    assert_eq!(set.insert(0), true);
    println!("{:?}", set.vec);
    assert_eq!(set.insert(1), true);
    println!("{:?}", set.vec);
    assert_eq!(set.remove(0), true);
    println!("{:?}", set.vec);
    assert_eq!(set.insert(2), true);
    println!("{:?}", set.vec);
    assert_eq!(set.remove(1), true);
    println!("{:?}", set.vec);
    assert_eq!(set.get_random(), 2);
    println!("{:?}", set.vec);
}