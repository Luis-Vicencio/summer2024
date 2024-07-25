use std::process::Command;
use std::io::{self, Write};

fn executing_os_commands_linux(command_full:&str) {

    let parts: Vec<&str> = command_full.split_whitespace().collect();
    let actual_command = parts[0];
    let arg1 = parts[1];

    let output = Command::new(actual_command)
        .arg(arg1)
        .output()
        .unwrap();
        //.expect("Failed to execute command");

    //println!("{:?}", output)
    println!("Command output: {}", String::from_utf8_lossy(&output.stdout));
}

fn accept_linux_command_from_user() -> String {

    let mut buffer = String::new();
    print!("Input Linux Command: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut buffer).unwrap();
    let command = buffer.trim().to_string();
    command
}

fn main(){

    let full_command:String = accept_linux_command_from_user();
    executing_os_commands_linux(&full_command);

}