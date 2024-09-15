// Copyright (c) 2024 igozdev 
// See end of file for full copyright information
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <cstdlib> // `EXIT_FAILURE`
#include <string_view>
#include <fstream>
#include <iterator>
#include <filesystem>
#include "tokenize/tokenize.hpp"
#include "tokenize/token_formatter.hpp"
#include "parse/parse.hpp"
#include "parse/node_formatter.hpp"
#include "emit/emit.hpp"

int main(int const argc, char const* const* const argv) {
    if (argc != 2) {
        fmt::print("Expected file name as argument.");
        return EXIT_FAILURE;
    }
    
    auto compile = [] [[nodiscard]] (this auto& self, std::string_view path) noexcept -> std::string {
        std::ifstream file{ std::filesystem::path(path) };
        if (!file) {
            fmt::print("Failed to read file {}", path); 
            return {};
        }
        std::string source{ std::istreambuf_iterator<char>(file), {} };

        auto const tokens = tokenize(source);
        auto const ast = parse(tokens);
        auto const output = emit(ast);
        return fmt::format("{}", output);
    };
    
    auto const output = compile(argv[1]);

    fmt::print("{}\n", output);
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
