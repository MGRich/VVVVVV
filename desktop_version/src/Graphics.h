#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "GraphicsResources.h"
#include <vector>
#include "Game.h"

#include "Maths.h"
#include "Textbox.h"
#include "UtilityClass.h"
#include "Game.h"


#include <string>
#include <algorithm>

#include "GraphicsUtil.h"
#include "Screen.h"

class map;

class Graphics
{
public:
	Graphics();
	~Graphics();

	float lerp(const float v0, const float v1, const float alpha);

	GraphicsResources grphx;

	int bfontlen(char32_t ch);
	int font_idx(char32_t ch);

	void Makebfont();

	void drawhuetile(int x, int y, int t, int c);

	void drawgravityline(int t, entityclass& obj);

	void MakeTileArray();

	void MakeSpriteArray();

	void maketelearray();

	void drawcoloredtile(int x, int y, int t, int r, int g, int b);

	void drawmenu(Game& game, int cr, int cg, int cb, int division = 30);
	void drawlevelmenu(Game& game, int cr, int cg, int cb, int division = 30);

	void processfade();

	void drawfade(const float alpha = 1.f);

	void setwarprect(int a, int b, int c, int d);

	void createtextbox(std::string t, int xp, int yp, int r = 255, int g = 255, int b = 255);

	void textboxcleanup();

	void textboxcenter();

	void textboxcenterx();

	int textboxwidth();

	void textboxmove(int xo, int yo);

	void textboxmoveto(int xo);

	void textboxcentery();

	void textboxadjust();

	void addline(std::string t);

	void textboxtimer(int t);

	void textboxremove();

	void textboxremovefast();

	void textboxactive();

	void drawtextbox(int x, int y, int w, int h, int r, int g, int b);

	void drawpixeltextbox(int x, int y, int w, int h, int w2, int h2, int r, int g, int b, int xo, int yo);
	void drawcustompixeltextbox(int x, int y, int w, int h, int w2, int h2, int r, int g, int b, int xo, int yo);

	void drawcrewman(int x, int y, int t, bool act, UtilityClass& help, bool noshift = false);

	int crewcolour(const int t);

	void cutscenebars();

	void drawpartimage(int t, int xp, int yp, int wp, int hp);

	void drawimage(int t, int xp, int yp, bool cent = false);

	void drawimagecol(int t, int xp, int yp, int r, int g, int b, bool cent = false);

	void drawguifixed();
	void drawgui(UtilityClass& help);

	void drawsprite(int x, int y, int t, int r, int g, int b);

	void printcrewname(int x, int y, int t);

	void printcrewnamestatus(int x, int y, int t);

	void printcrewnamedark(int x, int y, int t);

	void Print(int _x, int _y, std::string _s, int r, int g, int b, bool cen = false);

	void RPrint(int _x, int _y, std::string _s, int r, int g, int b, bool cen = false);

	void PrintOff(int _x, int _y, std::string _s, int r, int g, int b, bool cen = false);

	void bprint(int x, int y, std::string t, int r, int g, int b, bool cen = false);

	int len(std::string t);
	void bigprint(int _x, int _y, std::string _s, int r, int g, int b, bool cen = false, int sc = 2);
	void drawspritesetcol(int x, int y, int t, int c, UtilityClass& help);


	void flashlight();
	void screenshake();

	void render();

	bool Hitest(SDL_Surface* surface1, point p1, int col, SDL_Surface* surface2, point p2, int col2);

	void drawentitiesfixed(entityclass& obj, UtilityClass& help);
	void drawentities(mapclass& map, entityclass& obj, UtilityClass& help, const float alpha);

	void drawtrophytext(entityclass&, UtilityClass& help);

	void bigrprint(int x, int y, std::string& t, int r, int g, int b, bool cen = false, float sc = 2);


	void drawtele(int x, int y, int t, int c, UtilityClass& help);

	Uint32 getRGB(Uint8 r, Uint8 g, Uint8 b);

	Uint32 getBGR(Uint8 r, Uint8 g, Uint8 b);

	Uint32 getRGB(Uint32 _col);

	Uint32 RGBflip(Uint8  r, Uint8  g, Uint8  b);


	Uint32 RGBf(int r, int g, int b);

	void setcolreal(Uint32 t);

	void drawbackgroundfixed(int t);
	void drawbackground(int t, mapclass& map, const float deltatime);
	void drawtile3( int x, int y, int t, int off, bool flip = false );
	void drawentcolours( int x, int y, int t);
	void drawtile2( int x, int y, int t, int r, int g, int b );
	void drawtile( int x, int y, int t, int r, int g, int b );
	void drawtowertile( int x, int y, int t );
	void drawtowertile3( int x, int y, int t, int off, bool flip = false );

	void drawtile(int x, int y, int t);

	void drawmap(mapclass& map, int k, bool c = false);

	void drawfinalmapfixed(mapclass& map);

	void drawforetile(int x, int y, int t);

	void drawforetile2(int x, int y, int t);

	void drawforetile3(int x, int y, int t, int off);

	void drawrect(int x, int y, int w, int h, int r, int g, int b);

	void drawtowermap(mapclass& map, const float alpha);

	void drawtowermap_nobackground(mapclass& map, const float alpha);

	void drawtowerspikes(mapclass& map);

	void drawtowerentities(mapclass& map, entityclass& obj, UtilityClass& help, const float alpha);

	bool onscreen(int t);

	void drawtowerbackgroundsolo(mapclass& map);


	void menuoffrender();

	void drawtowerbackground(mapclass& map, const float alpha);

	void setcolourtransform(Uint32& colourtransform, const int colour, UtilityClass& help);
	void setcol(Uint32 colour);

	void drawfinalmap(mapclass& map, int k, bool c = false);

	colourTransform ct;

	std::string tempstring;

	int bcol, bcol2, rcol;

	std::string custom = "";

	int mapoff = 53;

	int j, k, m;

	growing_vector <SDL_Surface*> backgrounds;
	growing_vector <SDL_Surface*> images;

	growing_vector <SDL_Surface*> tele;
	growing_vector <SDL_Surface*> tiles;
	growing_vector <SDL_Surface*> tiles2;
	growing_vector <SDL_Surface*> tiles3;
	growing_vector <SDL_Surface*> entcolours;
	growing_vector <SDL_Surface*> sprites;
	growing_vector <SDL_Surface*> flipsprites;
	growing_vector <SDL_Surface*> bfont;
	growing_vector <SDL_Surface*> bfontmask;
	growing_vector <SDL_Surface*> flipbfont;
	growing_vector <SDL_Surface*> flipbfontmask;

	bool flipmode;
	bool setflipmode;
	bool notextoutline;
	point tl;
	//buffer objects. //TODO refactor buffer objects
	SDL_Surface* backBuffer;
	Screen* screenbuffer;
	SDL_Surface* menubuffer;
	SDL_Surface* towerbuffer;
	SDL_Surface* foregroundBuffer;
	SDL_Surface* tempBuffer;
	SDL_Surface* yBuffer;
	SDL_Surface* xBuffer;

	SDL_Rect bfont_rect;
	SDL_Rect tiles_rect;
	SDL_Rect sprites_rect;
	SDL_Rect bfontmask_rect;
	SDL_Rect images_rect;
	SDL_Rect bg_rect;
	SDL_Rect line_rect;
	SDL_Rect tele_rect;

	SDL_Rect foot_rect;
	SDL_Rect prect;
	SDL_Rect footerrect;

	int linestate, linedelay;
	float backoffset;
	bool backgrounddrawn, foregrounddrawn;

	int menuoffset;
	bool resumegamemode;

	SDL_Rect warprect;

	int crewframe;
	int crewframedelay;

	int fademode;
	int fadeamount;
	int oldfadeamount;
	growing_vector <int> fadebars;

	bool trinketcolset;
	int trinketr, trinketg, trinketb;

	growing_vector <textboxclass> textbox;
	int ntextbox;

	bool showcutscenebars;
	int cutscenebarspos;

	growing_vector<RectFloat> stars;
	growing_vector<int> starsspeed;

	int spcol, spcoldel;
	growing_vector<RectFloat> backboxes;
	growing_vector<int> backboxvx;
	growing_vector<int> backboxvy;
	growing_vector<float> backboxint;
	SDL_Rect backboxrect;

	int warpskip, warpfcol, warpbcol;

	Uint32 inactiveteleportercolour;
	Uint32 activeteleportercolour;
	Uint32 teleporterinactioncolour;
	void setcolourtoteleportercolour(int colour);
	void setteleportercolours(UtilityClass& help);
	bool specialwarp = false;
	int camxoff = 0;
	int camyoff = 0;
	float camxpre = 0, camypre = 0;
	int camspeed = 5;

	bool widescreen;
	bool whatthefuck = false;
};

#endif /* GRAPHICS_H */
