#include "Ticket.h"

Ticket::Ticket(const Movie& movie, const std::string& showtime, const std::string& seatNumber)
    : movie(movie), showtime(showtime), seatNumber(seatNumber) {}

const Movie& Ticket::getMovie() const {
    return movie;
}

const std::string& Ticket::getShowtime() const {
    return showtime;
}

const std::string& Ticket::getSeatNumber() const {
    return seatNumber;
}
