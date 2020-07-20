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
 * @file        File.cpp
 * @copyright   (c) 2017, DigiDNA - www.digidna.net
 * @author      Jean-David Gadina - www.digidna.net
 */

#include <ISOBMFF/File.hpp>

namespace ISOBMFF
{
    class File::IMPL
    {
        public:
            
            IMPL();
            IMPL( const IMPL & o );
            ~IMPL();
    };
    
    File::File():
        ContainerBox( "????" ),
        impl( std::make_unique< IMPL >() )
    {}
    
    File::File( const File & o ):
        ContainerBox( o ),
        impl( std::make_unique< IMPL >( *( o.impl ) ) )
    {}
    
    File::File( File && o ) ISOBMFF_NOEXCEPT( true ):
        ContainerBox( std::move( o ) ),
        impl( std::move( o.impl ) )
    {
        o.impl = nullptr;
    }
    
    File::~File()
    {}
    
    File & File::operator =( File o )
    {
        ContainerBox::operator=( o );
        swap( *( this ), o );
        
        return *( this );
    }
    
    void swap( File & o1, File & o2 )
    {
        using std::swap;
        
        swap( static_cast< ContainerBox & >( o1 ), static_cast< ContainerBox & >( o2 ) );
        swap( o1.impl, o2.impl );
    }
    
    std::string File::GetName() const
    {
        return "ISOBMFF::File";
    }
    
    File::IMPL::IMPL()
    {}

    File::IMPL::IMPL( const IMPL & o )
    {
        ( void )o;
    }

    File::IMPL::~IMPL()
    {}
}
