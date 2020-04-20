// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(Example, EmptyTest) {
URL one = URL("https://mail.ru/hello/hi.txt");
URL two = URL("https://mail.ru/");
URL three = URL("https://mail.ru");
URL four = URL("http://mail.ru/hello/hi.txt");
URL five = URL("http://mail.ru/");
URL six = URL("http://mail.ru");

EXPECT_EQ(one.protocol, "https:");
EXPECT_EQ(two.protocol, "https:");
EXPECT_EQ(three.protocol, "https:");
EXPECT_EQ(four.protocol, "http:");
EXPECT_EQ(five.protocol, "http:");
EXPECT_EQ(six.protocol, "http:");

EXPECT_EQ(one.host, "mail.ru");
EXPECT_EQ(two.host, "mail.ru");
EXPECT_EQ(three.host, "mail.ru");
EXPECT_EQ(four.host, "mail.ru");
EXPECT_EQ(five.host, "mail.ru");
EXPECT_EQ(six.host, "mail.ru");

EXPECT_EQ(one.path, "/hello/hi.txt");
EXPECT_EQ(two.path, "/");
EXPECT_EQ(three.path, "/");
EXPECT_EQ(four.path, "/hello/hi.txt");
EXPECT_EQ(five.path, "/");
EXPECT_EQ(six.path, "/");

EXPECT_EQ(one.port, "443");
EXPECT_EQ(two.port, "443");
EXPECT_EQ(three.port, "443");
EXPECT_EQ(four.port, "80");
EXPECT_EQ(five.port, "80");
EXPECT_EQ(six.port, "80");
}