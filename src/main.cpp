#include "BaseApp.hpp"
#include <iostream>

class Example : public BaseApp {
    public:
        Example(Ogre::String name="OgreBook_Example") : BaseApp(name) {}
    protected:
        void createScene() override
        {
            mScnMgr->setAmbientLight(Ogre::ColourValue(1.0F,1.0F,1.0F));

            Ogre::SceneNode* node = mScnMgr->createSceneNode("Node1");
            mScnMgr->getRootSceneNode()->addChild(node);
            node->setPosition(40.0F, 10.0F, 0.0F);
            node->yaw(Ogre::Degree(180.0f));
            Ogre::Entity* ent = mScnMgr->createEntity("MyEntity", "Sinbad.mesh");
            node->attachObject(ent);

            Ogre::Entity* ent2 = mScnMgr->createEntity("MyEntitysNinja", "ninja.mesh"); 
            Ogre::SceneNode* node2 = node->createChildSceneNode("Node2");
            node2->setPosition(10.0F, 0.0F, 10.0F);
            node2->setScale(0.02F, 0.02F, 0.02F);
            node2->attachObject(ent2);

        }
};

int main(int argc, char** argv)
{
    try {
        Example app ("Ejemplo 5");
        app.initApp();
        app.getRoot()->startRendering();
        app.closeApp();
    } catch (const std::exception& e) {
        std::cerr << "Error occurred during execution: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}