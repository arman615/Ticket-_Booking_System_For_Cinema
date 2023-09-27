#include <iostream>
#include <vector>
#include "Movie.h"
#include "User.h"
#include "Ticket.h"

void registerMovie(std::vector<Movie>& movies, const std::string& title, int duration,
                   const std::string& rating, const std::vector<std::string>& showtimes) {
    Movie newMovie(title, duration, rating);
    for (const std::string& showtime : showtimes) {
        newMovie.addShowtime(showtime);
    }
    movies.push_back(newMovie);
    std::cout << "Movie registered successfully.\n";
}

void registerUser(std::vector<User>& users, const std::string& name, const std::string& contactInfo) {
    User newUser(name, contactInfo);
    users.push_back(newUser);
    std::cout << "User registered successfully.\n";
}

bool isShowtimeAvailable(const Movie& movie, const std::string& showtime) {
    const std::vector<std::string>& showtimes = movie.getShowtimes();
    for (const std::string& time : showtimes) {
        if (time == showtime) {
            return true;
        }
    }
    return false;
}

void bookTicket(std::vector<Movie>& movies, std::vector<User>& users, std::vector<Ticket>& tickets,
                const std::string& movieTitle, const std::string& showtime, const std::string& userName,
                const std::string& userContactInfo, const std::string& seatNumber) {
    Movie* selectedMoviePtr = nullptr;
    for (Movie& movie : movies) {
        if (movie.getTitle() == movieTitle && isShowtimeAvailable(movie, showtime)) {
            selectedMoviePtr = &movie;
            break;
        }
    }
    if (selectedMoviePtr == nullptr) {
        std::cout << "Invalid movie selection or showtime is not available.\n";
        return;
    }

    User newUser(userName, userContactInfo);
    users.push_back(newUser);

    Ticket newTicket(*selectedMoviePtr, showtime, seatNumber);
    tickets.push_back(newTicket);

    std::cout << "Ticket booked successfully!\n";
}

void searchMovies(const std::vector<Movie>& movies, double maxDuration, const std::string& rating) {
    std::cout << "Search Results:\n";
    for (const Movie& movie : movies) {
        if (movie.getDuration() <= maxDuration && movie.getRating() == rating) {
            std::cout << "Title: " << movie.getTitle() << std::endl;
            std::cout << "Duration: " << movie.getDuration() << " minutes" << std::endl;
            std::cout << "Rating: " << movie.getRating() << std::endl;
            std::cout << "------------------------\n";
        }
    }
}

void generateTicket(const Ticket& ticket) {
    std::cout << "Ticket\n";
    std::cout << "Movie Title: " << ticket.getMovie().getTitle() << std::endl;
    std::cout << "Showtime: " << ticket.getShowtime() << std::endl;
    std::cout << "Seat Number: " << ticket.getSeatNumber() << std::endl;
    std::cout << "------------------------\n";
}

void generateMovieReport(const Movie& movie, const std::vector<Ticket>& tickets) {
    std::ofstream file(movie.getTitle() + "_report.txt");
    if (file.is_open()) {
        file << "Movie Report: " << movie.getTitle() << std::endl;
        for (const std::string& showtime : movie.getShowtimes()) {
            file << "Showtime: " << showtime << std::endl;
            file << "Booked Seats: ";
            for (const Ticket& ticket : tickets) {
                if (ticket.getMovie().getTitle() == movie.getTitle() && ticket.getShowtime() == showtime) {
                    file << ticket.getSeatNumber() << " ";
                }
            }
            file << "\n\n";
        }
        file.close();
        std::cout << "Movie report generated and saved to file successfully.\n";
    } else {
        std::cout << "Unable to generate movie report or save to file.\n";
    }
}

int main() {
    std::vector<Movie> movies;
    std::vector<User> users;
    std::vector<Ticket> tickets;

    registerMovie(movies, "The scent of a woman", 150, "PG-13",
                  {"2023-07-15 10:00", "2023-07-15 14:30", "2023-07-15 19:00"});
    registerMovie(movies, "The Titanic", 120, "PG-13",{"2023-07-15 11:30", "2023-07-15 16:00", "2023-07-15 20:30"});

    registerUser(users, "Arman", "arman@gmail.com");
    registerUser(users, "Gago", "gago@gmail.com");

    bookTicket(movies, users, tickets, "The scent of a woman", "2023-07-15 10:00", "Arman", "arman@gmail.com", "A1");
    bookTicket(movies, users, tickets, "The Titanic", "2023-07-15 16:00", "Gago", "gago@gmail.com", "B5");

    generateTicket(tickets[0]);
    generateTicket(tickets[1]);

    generateMovieReport(movies[0], tickets);
    generateMovieReport(movies[1], tickets);

    searchMovies(movies, 130, "PG-13");

    return 0;
}
