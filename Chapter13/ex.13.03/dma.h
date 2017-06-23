// dma.h  -- abcDMA class, baseDMA class, lacksDMA class, 
//           and hasDMA class interface
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

/*
 * Abstract Base Class abcDMA
 */
class abcDMA 
{
private:
    char *label;
    int rating;
public:
    abcDMA(const char * l = "null", int r = 0);
    abcDMA(const abcDMA & rs);
    virtual ~abcDMA() { delete[] label; }
    virtual abcDMA & operator=(const abcDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,
        const abcDMA & rs);
    virtual void View() const = 0;
};

/*
 * Base Class Using DMA
 */
class baseDMA :public abcDMA 
{
public:
    baseDMA(const char * l = "null", int r = 0) 
        : abcDMA(l, r) {}
    baseDMA(const baseDMA & rs) : abcDMA(rs) {}
    virtual ~baseDMA() {}
    virtual void View() const { abcDMA::View(); }
};

/*
 * derived class without DMA
 */
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public abcDMA 
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const abcDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, 
                                     const lacksDMA & rs);
    virtual void View() const;
};

/*
 * derived class with DMA
 */
class hasDMA :public abcDMA 
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const abcDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA() { delete[] style; }
    hasDMA & operator=(const hasDMA & rs);  
    friend std::ostream & operator<<(std::ostream & os, 
                                     const hasDMA & rs);
    virtual void View() const;
};

#endif
