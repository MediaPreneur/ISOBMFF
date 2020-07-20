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
 * @file        DREF.cpp
 * @copyright   (c) 2017, DigiDNA - www.digidna.net
 * @author      Jean-David Gadina - www.digidna.net
 */

#include <ISOBMFF/DREF.hpp>
#include <ISOBMFF/ContainerBox.hpp>

namespace ISOBMFF
{
    class DREF::IMPL
    {
        public:
            
            IMPL();
            IMPL( const IMPL & o );
            ~IMPL();
            
            std::vector< std::shared_ptr< ISOBMFF::Box > > _boxes;
    };
    
    DREF::DREF():
        FullBox( "dref" ),
        impl( std::make_unique< IMPL >() )
    {}
    
    DREF::DREF( const DREF & o ):
        FullBox( o ),
        impl( std::make_unique< IMPL >( *( o.impl ) ) )
    {}
    
    DREF::DREF( DREF && o ) ISOBMFF_NOEXCEPT( true ):
        FullBox( std::move( o ) ),
        impl( std::move( o.impl ) )
    {
        o.impl = nullptr;
    }
    
    DREF::~DREF()
    {}
    
    DREF & DREF::operator =( DREF o )
    {
        FullBox::operator=( o );
        swap( *( this ), o );
        
        return *( this );
    }
    
    void swap( DREF & o1, DREF & o2 )
    {
        using std::swap;
        
        swap( static_cast< FullBox & >( o1 ), static_cast< FullBox & >( o2 ) );
        swap( o1.impl, o2.impl );
    }
    
    void DREF::ReadData( Parser & parser, BinaryStream & stream )
    {
        ContainerBox container( "????" );
        
        FullBox::ReadData( parser, stream );
        stream.ReadBigEndianUInt32();
        container.ReadData( parser, stream );
        
        this->impl->_boxes = container.GetBoxes();
    }
    
    void DREF::WriteDescription( std::ostream & os, std::size_t indentLevel ) const
    {
        FullBox::WriteDescription( os, indentLevel );
        Container::WriteBoxes( os, indentLevel );
    }
    
    void DREF::AddBox( std::shared_ptr< Box > box )
    {
        if( box != nullptr )
        {
            this->impl->_boxes.push_back( box );
        }
    }
    
    std::vector< std::shared_ptr< Box > > DREF::GetBoxes() const
    {
        return this->impl->_boxes;
    }
    
    DREF::IMPL::IMPL()
    {}

    DREF::IMPL::IMPL( const IMPL & o ):
        _boxes( o._boxes )
    {}

    DREF::IMPL::~IMPL()
    {}
}
