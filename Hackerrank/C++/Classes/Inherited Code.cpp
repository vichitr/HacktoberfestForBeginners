class BadLengthException
{
public:

    BadLengthException(int n)
    {
        this->n = n;
    }
  virtual const int what() const throw()
  {
    return n;
  }
  
  int n;
}; 