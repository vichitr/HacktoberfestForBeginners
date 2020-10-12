template <>
struct Traits<Color>
{

    string static name(int color)
    {
        if (color == 0)
        {
            return "red";
        }
        else if (color == 1)
        {
            return "green";
        }
        else if (color == 2)
        {
            return "orange";
        }
        else
        {
            return "unknown";
        }
    }
};
template <>
struct Traits<Fruit>
{
    string static name(int type)
    {
        if (type == 0)
        {
            return "apple";
        }
        else if (type == 1)
        {
            return "orange";
        }
        else if (type == 2)
        {
            return "pear";
        }
        else
        {
            return "unknown";
        }
    }
};