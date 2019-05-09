
#ifndef ERRORS_H
#define ERRORS_H

class BadElementId : public std::exception
{
public:
  virtual char const * what() const noexcept { return "Invalid element ID requested!"; }
};

class IdAlreadyExists : public std::exception
{
public:
  virtual char const * what() const noexcept { return "Requested ID already exists!"; }
};

class BadTitle : public std::exception
{
public:
  virtual char const * what() const noexcept { return "Parent directory has the same child!"; }
};

class BadParentId : public std::exception
{
public:
  virtual char const * what() const noexcept { return "Parent ID is not referring to a directory!"; }
};

class BadLinkedElement : public std::exception
{
public:
  virtual char const * what() const noexcept { return "Invalid element type requested! "; }
};


#endif
