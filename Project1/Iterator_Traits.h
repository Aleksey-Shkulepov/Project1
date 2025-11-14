#pragma once

struct Input_Iterator_Tag {};
struct Forward_Iterator_Tag : Input_Iterator_Tag {};
struct Bidirectional_Iterator_Tag : Forward_Iterator_Tag {};
struct Random_Access_Iterator_Tag : Bidirectional_Iterator_Tag {};
