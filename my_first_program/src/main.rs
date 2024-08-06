fn enum_as_struct_field() {
    #[derive(Debug)]
    #[allow(dead_code)]
    enum Genre {
        Fiction,
        NonFiction,
        ScienceFiction,
    }

    #derive(Debug)
    enum Year {
        Freshman,
        Sophmore,
        Junior,
        Senior
    }
    
    struct Student {
        name: String,
        year: Year,
        gpa: f32,
    }

    impl Student{
        fn new(name:&str,year:Year) -> {
            Student{
                name: name.to_string();
                year:year,
                gpa: 3.5,
            }
        }
    }
    
    let my_book = Book {
        title: String::from("Rust Programming"),
        genre: Genre::NonFiction,
        review_score: 5,
    };
}

fn main(){

    println!("{} is a {:?} book with a score of {}", my_book.title, my_book.genre, my_book.review_score);
}