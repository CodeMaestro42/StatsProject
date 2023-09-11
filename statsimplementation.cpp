// statsimplementation.cpp
// statisticianproject
//
// Created by Matthew Ramos on 2/13/22.
#include "stats.h"

namespace Statistician_Project {

statistician::statistician() {
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;
}

void statistician::next(double r) {
    if (count == 0) {
        tinyest = largest = r;
    }

    count++;
    total += r;

    if (r > largest) {
        largest = r;
    }

    if (r < tinyest) {
        tinyest = r;
    }
}

void statistician::reset() {
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;
}

int statistician::length() const {
    return count;
}

double statistician::sum() const {
    return total;
}

double statistician::mean() const {
    return total / count;
}

double statistician::minimum() const {
    return tinyest;
}

double statistician::maximum() const {
    return largest;
}

statistician operator+(const statistician &s1, const statistician &s2) {
    statistician temp;

    if (s1.length() == 0) {
        temp.count = s2.length();
        temp.total = s2.sum();
        temp.tinyest = s2.minimum();
        temp.largest = s2.maximum();
    } else if (s2.length() == 0) {
        temp.count = s1.length();
        temp.total = s1.sum();
        temp.tinyest = s1.minimum();
        temp.largest = s1.maximum();
    } else {
        temp.count = s1.length() + s2.length();
        temp.total = s1.sum() + s2.sum();

        if (s1.maximum() >= s2.maximum()) {
            temp.largest = s1.maximum();
        } else {
            temp.largest = s2.maximum();
        }

        if (s1.minimum() <= s2.minimum()) {
            temp.tinyest = s1.minimum();
        } else {
            temp.tinyest = s2.minimum();
        }
    }

    return temp;
}

statistician operator*(double scale, const statistician &s) {
    statistician temp;
    temp.count = s.length();
    temp.total = s.sum() * scale;
    temp.largest = s.maximum() * scale;
    temp.tinyest = s.minimum() * scale;

    if (temp.largest < temp.tinyest) {
        double largest_value = temp.largest;
        temp.largest = temp.tinyest;
        temp.tinyest = largest_value;
    }

    return temp;
}

bool operator==(const statistician &s1, const statistician &s2) {
    if (s1.length() == 0 && s2.length() == 0) {
        return true;
    }

    return (s1.length() == s2.length() && s1.sum() == s2.sum() && s1.mean() == s2.mean() &&
            s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum());
}

} // namespace Statistician_Project




