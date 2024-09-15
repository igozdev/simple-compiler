// Copyright (c) 2024 igozdev 
// See end of file for full copyright information
#pragma once
#include <vector>
#include "node.hpp"
#include "../tokenize/token.hpp"

[[nodiscard]] inline auto parse_something(std::vector<token> const& tokens, std::size_t& i) noexcept -> std::vector<node>;
// TODO

[[nodiscard]] inline auto parse(std::vector<token> const& tokens) noexcept -> std::vector<node> {
    std::vector<node> result;
    for (auto i = 0zu; i < tokens.size();) {
        auto const nodes = parse_something(tokens, i);
        result.insert(result.end(), nodes.begin(), nodes.end());
    }
    return result;
};

[[nodiscard]] inline auto parse_something(std::vector<token> const& tokens, std::size_t& i) noexcept -> std::vector<node> {
    // TODO
    return { node{ .t = tokens[i++] } };
}

// MIT License
// 
// Copyright (c) 2024 igozdev
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
