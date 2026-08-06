use std::collections::HashMap;

fn word_frequency(text: &str) -> HashMap<String, usize> {
    let mut map = HashMap::new();

    for word in text
        .split_whitespace()
        .map(|w| w.trim_matches(|c: char| !c.is_alphanumeric()).to_lowercase())
        .filter(|w| !w.is_empty())
    {
        *map.entry(word).or_insert(0) += 1;
    }

    map
}

fn main() {
    let text = "Rust is fast. Rust is safe. Rust is awesome!";

    let frequencies = word_frequency(text);

    println!("Word Frequency Counter\n");

    let mut words: Vec<_> = frequencies.iter().collect();
    words.sort_by_key(|(word, _)| *word);

    for (word, count) in words {
        println!("{:<10} {}", word, count);
    }
}