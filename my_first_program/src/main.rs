use std::io;

fn main() {
    let mut secret = 12; 
    let mut counter = 0;

    fn check_guess(guess: i32, secret: i32) -> i32 {
        if secret == guess {
            0
        } else if secret > guess {
            1
        } else {
            -1
        }
    }

    loop {
        println!("Insert number: ");

        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            .expect("Failed to read line");

        let guess: i32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        counter += 1;

        match check_guess(guess, secret) {
            0 => {
                println!("Correct.");
                println!("Total guesses: {}", counter);
                break;
            },
            1 => println!("Too low."),
            -1 => println!("Too high."),
            _ => println!("Unexpected result."),
        }
    }
}

