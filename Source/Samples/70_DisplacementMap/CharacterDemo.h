//
// Copyright (c) 2008-2016 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "Sample.h"

namespace Urho3D
{
class Node;
class Scene;
}

class Character;
class DisplacementMap;
//=============================================================================
//=============================================================================
/// Moving character example.
class CharacterDemo : public Sample
{
    URHO3D_OBJECT(CharacterDemo, Sample);

public:
    /// Construct.
    CharacterDemo(Context* context);
    /// Destruct.
    ~CharacterDemo();

    virtual void Setup();
    /// Setup after engine initialization and before running the main loop.
    virtual void Start();

protected:
    /// Create static scene content.
    void CreateScene();
    void ChangeDebugHudText();

    /// Create controllable character.
    void CreateCharacter();
    /// Construct an instruction text to the UI.
    void CreateInstructions();

    void SetupDisplacementVars();
    BoundingBox GetFootBoundingBox(Node *footNode, Node *toeBase);
    void UpdateDisplacementMap();

    /// Subscribe to necessary events.
    void SubscribeToEvents();
    /// Handle application update. Set controls to character.
    void HandleUpdate(StringHash eventType, VariantMap& eventData);
    /// Handle application post-update. Update camera position after character has moved.
    void HandlePostUpdate(StringHash eventType, VariantMap& eventData);
    void HandlePostRenderUpdate(StringHash eventType, VariantMap& eventData);

protected:
    /// The controllable character component.
    WeakPtr<Character> character_;
    /// First person camera flag.
    bool firstPerson_;

    bool drawDebug_;
    bool wireView_;

    // displacemet map
    SharedPtr<DisplacementMap> displacementMap_;
    Timer dispUpdateTimer_;

    // char
    Vector3     prevCharPos_;

    // char feet
    WeakPtr<Node> charRgtFootNode_;
    WeakPtr<Node> charLftFootNode_;
    BoundingBox charRgtFootBBox_;
    BoundingBox charLftFootBBox_;

};
