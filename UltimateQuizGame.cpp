#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  

bool caseInsensitiveCompare(char a, char b) {
    return std::tolower(a) == std::tolower(b);
}

// Case-insensitive string comparison
bool caseInsensitiveStringCompare(const std::string& str1, const std::string& str2) {
    return str1.size() == str2.size() &&
           std::equal(str1.begin(), str1.end(), str2.begin(), caseInsensitiveCompare);
}

bool askQuestion(const std::string& question, const std::string& correctAnswer) {
    std::string userAnswer;
    std::cout << question << " ";
    std::getline(std::cin, userAnswer);

    return caseInsensitiveStringCompare(userAnswer, correctAnswer);
}

int main() {
    std::cout << "Welcome to the Ultimate Quiz Game!\n";

    std::vector<std::pair<std::string, std::string>> questions = {
        {"What is the capital of France?", "Paris"},
        {"Which planet is known as the Red Planet?", "Mars"},
        {"What is the largest mammal in the world?", "Blue Whale"},
        {"Which programming language is known for its use in web development?", "JavaScript"},
        {"In what year did the Titanic sink?", "1912"},
        {"Who wrote 'Romeo and Juliet'?", "William Shakespeare"},
        {"What is the powerhouse of the cell?", "Mitochondria"},
        {"Which country is known as the Land of the Rising Sun?", "Japan"},
        {"What is the largest ocean on Earth?", "Pacific Ocean"},
        {"Who developed the theory of relativity?", "Albert Einstein"},
        {"What is the capital of Australia?", "Canberra"},
        {"Which famous scientist formulated the laws of motion and universal gravitation?", "Isaac Newton"},
        {"What is the largest desert in the world?", "Sahara"},
        {"Who is known as the 'Father of Computer Science'?", "Alan Turing"},
        {"What is the currency of Japan?", "Japanese Yen"},
        {"Which planet is known as the 'Morning Star' or 'Evening Star'?", "Venus"},
        {"Who wrote the 'Harry Potter' book series?", "J.K. Rowling"},
        {"What is the speed of light in a vacuum?", "299,792 kilometers per second"},
        {"In which year did the Berlin Wall fall?", "1989"},
        {"What is the national flower of Japan?", "Cherry Blossom"},
        {"Who painted 'Starry Night'?", "Vincent van Gogh"},
        {"What is the square root of 144?", "12"},
        {"Which gas is most abundant in Earth's atmosphere?", "Nitrogen"},
        {"What is the smallest prime number?", "2"},
        {"Who discovered penicillin?", "Alexander Fleming"},
    };

    int score = 0;

    for (const auto& questionData : questions) {
        const std::string& question = questionData.first;
        const std::string& correctAnswer = questionData.second;

        if (askQuestion(question, correctAnswer)) {
            std::cout << "Correct! You got it right.\n";
            score += 1;
        } else {
            std::cout << "Wrong! The correct answer is " << correctAnswer << ".\n";
        }
    }

    std::cout << "\nQuiz complete. Your score: " << score << " out of " << questions.size() << ".\n";

    return 0;
}
