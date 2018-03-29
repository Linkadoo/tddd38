#include <sstream>
#include <iterator>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <memory>
using namespace std;

// Given, should not be changed
struct Image_Data
{
    Image_Data(string const & line)
    {
        istringstream iss{line};
        iss >> type;
        for ( int d; iss >> d; )
        {
            args.push_back(d);
        }
    }
    string type;
    vector<int> args;
};

// Add your classes here
class Image
{
public:
  virtual ~Image() = default;

  //virtual Image parse(Image_Data) = 0;
  virtual int size() = 0;

protected:
  Image(int width, int height) : width{width}, height{height} {}
  int width, height;
};

class PNG : public Image
{
public:
  ~PNG() = default;
  PNG(int width, int height) : Image(width,height) {}

  int size() override { return (width*height)*1.5; }
  static PNG* parse(Image_Data im)
  {
    if(im.type != "PNG")
      return nullptr;
    return new PNG(im.args[0], im.args[1]);
  }
};

class JPG : public Image
{
public:
  ~JPG() = default;
  JPG(int width, int height, int quality) : Image{width,height}, quality{quality} {}

  int size() override { return (width*height*3) * (quality/100.0); }
  static JPG* parse(Image_Data im)
  {
    if(im.type != "JPG")
      return nullptr;
    return new JPG(im.args[0], im.args[1], im.args[2]);
  }
private:
  int quality;
};

class BMP : public Image
{
public:
  ~BMP() = default;
  BMP(int width, int height) : Image(width,height) {}

  int size() override { return width*height*3; }
  static BMP* parse(Image_Data im)
  {
    if(im.type != "BMP")
      return nullptr;
    return new BMP(im.args[0], im.args[1]);
  }
};


/*
 * Given code. No modifications allowed unless specified!
 */
Image* error_printer(Image_Data const & d)
{
    cout << "!!! " << d.type << " is an invalid file format !!!\n";
    return nullptr;
}
int main()
{
    vector<unique_ptr<Image>> images;
    vector<function<Image*(Image_Data const &)>> funs { PNG::parse,
                                                        JPG::parse,
                                                        BMP::parse,
                                                        error_printer};
    cout << "Enter one line for each image on the format \"type [type specific data]\". Exit with \"q\".\n\n";

    for ( string line; getline(cin, line); )
    {
        if ( line == "q" )
        {
            break;
        }
        Image_Data data{line};
        for ( auto && f: funs )
        {
            if (auto ptr = f(data))
            {
                images.emplace_back(ptr);
                break;
            }
        }
    }

// Additions allowed below (calculate and print sum)




}
