// Copyright 2020 telsamar

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <regex>
#include <fstream>
#include <boost/program_options.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <thread_pool/thread_pool.hpp>
#include "URL.hpp"

using boost::asio::io_context;
using tcp = boost::asio::ip::tcp;
using boost::beast::tcp_stream;
using boost::beast::flat_buffer;
using boost::beast::http::request;
using boost::beast::http::string_body;
using boost::beast::http::field;
using boost::beast::http::string_body;
using boost::beast::http::verb;
using boost::beast::http::write;
using boost::beast::http::field;
using boost::beast::http::response;
using boost::beast::http::dynamic_body;
using boost::beast::http::read;

#endif // INCLUDE_HEADER_HPP_
