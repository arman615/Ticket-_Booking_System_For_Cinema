#pragma once
#include <string>
#include <vector>

class Movie {
private:
    std::string title;
    int duration;
    std::string rating;
    std::vector<std::string> showtimes;

public:
    Movie(const std::string& title, int duration, const std::string& rating);

    const std::string& getTitle() const;
    int getDuration() const;
    const std::string& getRating() const;
    const std::vector<std::string>& getShowtimes() const;
    void addShowtime(const std::string& showtime);
};
