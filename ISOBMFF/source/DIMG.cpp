/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2017 DigiDNA - www.digidna.net
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        DIMG.cpp
 * @copyright   (c) 2017, DigiDNA - www.digidna.net
 * @author      Jean-David Gadina - www.digidna.net
 */

#include <ISOBMFF/DIMG.hpp>

namespace ISOBMFF
{
    class DIMG::IMPL
    {
        public:
            
            IMPL();
            IMPL( const IMPL & o );
            ~IMPL();
    };
    
    DIMG::DIMG():
        SingleItemTypeReferenceBox( "dimg" ),
        impl( std::make_unique< IMPL >() )
    {}
    
    DIMG::DIMG( const DIMG & o ):
        SingleItemTypeReferenceBox( o ),
        impl( std::make_unique< IMPL >( *( o.impl ) ) )
    {}
    
    DIMG::DIMG( DIMG && o ) ISOBMFF_NOEXCEPT( true ):
        SingleItemTypeReferenceBox( std::move( o ) ),
        impl( std::move( o.impl ) )
    {
        o.impl = nullptr;
    }
    
    DIMG::~DIMG()
    {}
    
    DIMG & DIMG::operator =( DIMG o )
    {
        SingleItemTypeReferenceBox::operator=( o );
        swap( *( this ), o );
        
        return *( this );
    }
    
    void swap( DIMG & o1, DIMG & o2 )
    {
        using std::swap;
        
        swap( static_cast< SingleItemTypeReferenceBox & >( o1 ), static_cast< SingleItemTypeReferenceBox & >( o2 ) );
        swap( o1.impl, o2.impl );
    }
    
    DIMG::IMPL::IMPL()
    {}

    DIMG::IMPL::IMPL( const IMPL & o )
    {
        ( void )o;
    }

    DIMG::IMPL::~IMPL()
    {}
}
