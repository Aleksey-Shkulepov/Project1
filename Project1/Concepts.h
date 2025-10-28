#pragma once

template<typename T>
concept HasLoad = requires(T t, std::ifstream & in) {
    t.load(in);
};
template<typename T>
concept HasSave = requires(T t, std::ofstream & out) {
    t.save(out);
};

