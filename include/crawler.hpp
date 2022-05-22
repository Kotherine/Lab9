// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_CRAWLER_HPP_
#define INCLUDE_CRAWLER_HPP_

#include <boost/asio/ip/tcp.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <string>

#include "consumer.hpp"
#include "producer.hpp"

namespace po = boost::program_options;

void crawler(std::string url, unsigned depth, Consumer& k, Producer &p,
             std::string outp, Queue &parser_queue);

#endif  // INCLUDE_CRAWLER_HPP_
