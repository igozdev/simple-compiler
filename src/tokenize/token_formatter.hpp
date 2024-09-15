// Copyright (c) 2024 igozdev 
// See end of file for full copyright information
#pragma once
#include <fmt/format.h>
#include "token.hpp"
#include "symbol_formatter.hpp"

template <> struct fmt::formatter<token> {
    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }
    template <typename Context> constexpr auto format(token const& t, Context& ctx) const {
        switch (t.type) {
        case token::identifier:
            return format_to(ctx.out(), "(identifier, \"{}\")", t.string_);
        case token::symbol:
            return format_to(ctx.out(), "(symbol, {})", t.symbol_);
        case token::integer:
            return format_to(ctx.out(), "(integer, {})", t.integer_);
        case token::character:
            return format_to(ctx.out(), "(character, '{}')", t.character_);
        case token::string:
            return format_to(ctx.out(), "(string, \"{}\")", t.string_);
        }
    }
};

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
