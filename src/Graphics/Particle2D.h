//
//  Particle2D.h
//  0729_DancePerformance
//
//  Created by Toyama Genki on 2016/07/23.
//
//

#pragma once

class Particle2D : public ofBaseApp {
private:
    ofVec2f _position;
    ofVec2f _velocity;
    ofVec2f _force;
    float _friction;
    float _radius;
    bool _bFixed;
    float _mass;
    
public:
    Particle2D()
    {
        _force = ofVec2f(0);
        _friction = 0.01;
        _bFixed = false;
    };
    
    ~Particle2D(){};
    
    void setup(ofVec2f position, ofVec2f velocity, float radius=1.0, float mass=1.0)
    {
        _position = position;
        _velocity = velocity;
        _radius = radius;
        _mass = mass;
    }
    
    void resetForce()
    {
        _force.set(0, 0);
    }
    
    void addForce(ofVec2f force)
    {
        _force += force / _mass;
    }

    void updateForce()
    {
        _force -= _velocity * _friction;
    }
    
    void updatePos()
    {
        if(!_bFixed)
        {
            _velocity += _force;
            _position += _velocity;
        }

    }
    
    void update()
    {
        updateForce();
        updatePos();
    }
   
    void draw()
    {
        ofDrawCircle(_position, _radius);
    }
    
    ofVec2f getPosition()
    {
        return _position;
    }
    
    ofVec2f getVelocity()
    {
        return _velocity;
    }
    
    
    void addRepulsionForce(float x, float y, float radius, float scale)
    {
        ofVec2f posForce;
        posForce.set(x,y);
        ofVec2f diff = _position - posForce;
        float length = diff.length();
        bool bAmCloseEnough = true;
        
        if (radius > 0)
        {
            if (length > radius)
            {
                bAmCloseEnough = false;
            }
        }
        
        if (bAmCloseEnough == true)
        {
            float pct = 1 - (length / radius);
            diff.normalize();
            _force.x = _force.x + diff.x * scale * pct;
            _force.y = _force.y + diff.y * scale * pct;
        }

    }
    
    void addRepulsionForce(Particle2D &p2D, float radius, float scale)
    {
        ofVec2f posForce;
        posForce.set(p2D._position.x,p2D._position.y);
        ofVec2f diff = _position - posForce;
        float length = diff.length();
        bool bAmCloseEnough = true;
        
        if (radius > 0)
        {
            if (length > radius)
            {
                bAmCloseEnough = false;
            }
        }
        
        if (bAmCloseEnough == true)
        {
            float pct = 1 - (length / radius);
            diff.normalize();
            _force.x = _force.x + diff.x * scale * pct;
            _force.y = _force.y + diff.y * scale * pct;
            p2D._force.x = p2D._force.x - diff.x * scale * pct;
            p2D._force.y = p2D._force.y - diff.y * scale * pct;
        }
    }
    
    void addAttractionForce(float x, float y, float radius, float scale)
    {
        ofVec2f posForce;
        posForce.set(x,y);
        ofVec2f diff = _position - posForce;
        float length = diff.length();
        bool bAmCloseEnough = true;
        
        if (radius > 0)
        {
            if (length > radius)
            {
                bAmCloseEnough = false;
            }
        }
        
        if (bAmCloseEnough == true)
        {
            float pct = 1 - (length / radius);
            diff.normalize();
            _force.x = _force.x - diff.x * scale * pct;
            _force.y = _force.y - diff.y * scale * pct;
        }
    }
    
    void addAttractionForce(Particle2D &p2D, float radius, float scale)
    {
        ofVec2f posForce;
        posForce.set(p2D._position.x, p2D._position.y);
        ofVec2f diff = _position - posForce;
        float length = diff.length();
        bool bAmCloseEnough = true;
        
        if (radius > 0)
        {
            if (length > radius)
            {
                bAmCloseEnough = false;
            }
        }
        
        if (bAmCloseEnough == true)
        {
            float pct = 1 - (length / radius);
            diff.normalize();
            _force.x = _force.x - diff.x * scale * pct;
            _force.y = _force.y - diff.y * scale * pct;
            p2D._force.x = p2D._force.x + diff.x * scale * pct;
            p2D._force.y = p2D._force.y + diff.y * scale * pct;
        }
    }
};