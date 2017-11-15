#include "Core.h"
#include "SDL.h"
#include "SDL_Image.h"
#include "SDL_ttf.h"
#include "SDL_Mixer.h"
#include "..\Base\Base.h"
#include "..\Graphics\SpriteManager.h"
#include "..\Graphics\Background.h"
#include "..\Logic\Object2DManager.h"
#include "..\GUI\GUIManager.h"
#include "..\Sound\SoundManager.h"
#include "..\Particles\ParticleManager.h"

CCore::~CCore()
{	
	CHECKED_DELETE(m_pParticleManager);
	CHECKED_DELETE(m_pSoundManager);
	CHECKED_DELETE(m_pGUIManager);
	CHECKED_DELETE(m_pBackground);
	CHECKED_DELETE(m_pObject2DManager);
	CHECKED_DELETE(m_pSpriteManager);
	CHECKED_DELETE_RENDERER(m_pRenderer);
	CHECKED_DELETE_WINDOW(m_pWindow);	

	//Quit SDL subsystems
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void CCore::Init(std::string sWindowName, 
				 int32 width,
				 int32 height,
				 std::string BackgroundFile)
{
	int32  l_ResInit = SDL_Init(SDL_INIT_EVERYTHING);
	assert(l_ResInit==0);
	//Init window and renderer
	int32 l_ResWindowCreate = SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL , &m_pWindow, &m_pRenderer);
	assert(l_ResWindowCreate==0);
	SDL_SetWindowTitle(m_pWindow, sWindowName.c_str());
	//Initialize renderer color
	SDL_SetRenderDrawColor( m_pRenderer, 0x00, 0x00, 0x00, 0xFF );
	SDL_SetRenderDrawBlendMode(m_pRenderer, SDL_BLENDMODE_BLEND);
	//Init image library
	int32 l_ResIMGInit = IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
	assert(l_ResIMGInit==(IMG_INIT_JPG|IMG_INIT_PNG));
	//Init text library
	int32 l_ResTTFInit = TTF_Init();
	assert(l_ResTTFInit==0);
	//Init sound
	int32 l_ResMixAudio = Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
	assert(l_ResMixAudio==0);

	//Create sprite manager
	m_pSpriteManager = new CSpriteManager();

	//Create Object Manager
	m_pObject2DManager = new CObject2DManager();

	//Create Background
	m_pBackground = new CBackground(BackgroundFile, m_pRenderer, width, height);

	//Create GUI Manager
	m_pGUIManager = new CGUIManager();

	//Create Sound Manager
	m_pSoundManager = new CSoundManager();

	//Create particle manager
	m_pParticleManager = new CParticleManager();
}

void CCore::BeginRender()
{
	SDL_RenderClear(m_pRenderer);
}

void CCore::EndRender()
{
	SDL_RenderPresent(m_pRenderer);
}