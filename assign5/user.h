/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);
  User& operator=(const User& user);
  User(const User& user);
  ~User();
  User(User&& user)=delete;
  User& operator=(User&& user)=delete;
  User&  operator+=(User& other);
  friend bool operator<(const User& lhs,const User& rhs);

	
  friend std::ostream& operator<<(std::ostream& out,const User& user);
  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};
