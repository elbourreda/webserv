#ifndef SERVERCONFIG_HPP
# define SERVERCONFIG_HPP

# include <vector>
# include <iostream>

# include "ServerRoutes.hpp"
# include "../utils.h"

using namespace std;

class ServerConfig
{
	private:
		long long				_body_size_limit;
		string					_host;
		string					_name;
		int						_port;
		vector< ServerRoutes >	_routes;
		string					_error_400;
		string					_error_403;
		string					_error_404;
		string					_error_405;
		string					_error_413;
		string					_error_502;

	public:
								ServerConfig( void );
								ServerConfig( ServerConfig const & );
		ServerConfig &			operator=( ServerConfig const & );
								~ServerConfig( void );

		string					getHost( void ) const;
		int						getPort( void ) const;
		long long				getBodySizeLimit( void ) const;
		string					getName( void ) const;
		vector< string >		getErrorPages( void ) const;
		ServerRoutes			getRootRoute( void ) const; // throw( string & )
		ServerRoutes			getRoute( int const & ) const; // throw( string & );
		ServerRoutes			getRoute( string ) const; // throw( string & );
		vector< ServerRoutes >	getRoutes( void ) const;
		int						getRouteCount( void ) const;

		void					setHost( string const & );
		void					setPort( int const & );
		void					setBodySizeLimit( long long const & );
		void					setName( string const & );
		void					addErrorPage( string const & );
		void					addRoute( ServerRoutes const & );


		string					get400Page( void ) const;
		void					set400Page( string const & );
		string					get403Page( void ) const;
		void					set403Page( string const & );
		string					get404Page( void ) const;
		void					set404Page( string const & );
		string					get405Page( void ) const;
		void					set405Page( string const & );
		string					get413Page( void ) const;
		void					set413Page( string const & );
		string					get502Page( void ) const;
		void					set502Page( string const & );
};

#endif