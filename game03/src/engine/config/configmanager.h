#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include<SDL3/SDL.h>
#include<fstream>

using json = nlohmann::json;

class ConfigManager {
private:
    json config;

    ConfigManager() = default;
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

public:
    static ConfigManager& getInstance() {
        static ConfigManager instance;
        return instance;
    }

    // Load config from JSON file
    bool load(const std::string& filepath) {
        try {
            std::ifstream file(filepath);
            if (!file.is_open()) {
                SDL_Log("");
                return false;
            }
            file >> config;
            return true;
        }
        catch (const json::exception& e) {
            std::cerr<< "JSON Error: " << e.what() << std::endl;
            return false;
        }
    }

    // Save config to JSON file
    bool save(const std::string& filepath) {
        try {
            std::ofstream file(filepath);
            file << config.dump(4);  // Pretty print with 4 spaces
            return true;
        }
        catch (const json::exception& e) {
            std::cerr << "JSON Error: " << e.what() << std::endl;
            return false;
        }
    }

    // Get values
    template<typename T>
    T get(const std::string& key, const T& defaultValue = T()) {
        try {
            return config[key].get<T>();
        }
        catch (...) {
            return defaultValue;
        }
    }

    // Get nested values
    template<typename T>
    T getPath(const std::string& path, const T& defaultValue = T()) {
        try {
            json value = config;
            std::istringstream iss(path);
            std::string key;
            while (std::getline(iss, key, '.')) {
                value = value[key];
            }
            return value.get<T>();
        }
        catch (...) {
            return defaultValue;
        }
    }

    // Set values
    template<typename T>
    void set(const std::string& key, const T& value) {
        config[key] = value;
    }

    // Get raw JSON
    const json& getJson() const {
        return config;
    }
};