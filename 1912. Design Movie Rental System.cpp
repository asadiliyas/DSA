class MovieRentingSystem {
public:
    set<vector<int>> rented;                                //{P,S,M}
    unordered_map<int, set<vector<int>>> unRented;          //{M,P,S}
    unordered_map<int, unordered_map<int, int>> price2DArr; //{M,S,P}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& i : entries) {
            int shop = i[0];
            int movie = i[1];
            int price = i[2];

            unRented[movie].insert({price, shop});
            price2DArr[movie][shop] = price;
        }
    }

    vector<int> search(int movie) {
        if (unRented.find(movie) == unRented.end()) {
            return {};
        }

        vector<int> ans;

        for (auto& v : unRented[movie]) {
            int shop = v[1];
            ans.push_back(shop);

            if (ans.size() == 5) {
                break;
            }
        }

        return ans;
    }

    void rent(int shop, int movie) {
        int price = price2DArr[movie][shop];
        unRented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = price2DArr[movie][shop];
        rented.erase({price, shop, movie});
        unRented[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto& ele : rented) {
            ans.push_back({ele[1], ele[2]});
            if (ans.size() == 5) {
                break;
            }
        }

        if (ans.size() == 0) {
            return {};
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
